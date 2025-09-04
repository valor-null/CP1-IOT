#include <Arduino.h>
#include <math.h>

constexpr int ADC_PIN = 34;  
constexpr int LED_POS = 2;     
constexpr int LED_NEG = 4;     

constexpr int FS_HZ  = 1000;    
constexpr int WIN_MS = 200;     
constexpr int N = FS_HZ * WIN_MS / 1000;

static float buf[N];


extern "C" double score(double input[]);

inline float adc_to_unit(int raw){ return raw / 4095.0f; }

void collect_window(float *dst, int n, int fs_hz){
  const uint32_t Ts_us = 1000000UL / fs_hz;
  for(int i=0;i<n;++i){
    dst[i] = adc_to_unit(analogRead(ADC_PIN));
    delayMicroseconds(Ts_us);
  }
}

void calc_all(const float *x, int n, float &mean, float &stddev, float &rms, float &ptp){
  double sum=0.0, sumsq=0.0;
  float xmin=x[0], xmax=x[0];
  for(int i=0;i<n;++i){
    float v = x[i];
    sum += v;
    sumsq += (double)v*v;
    if(v<xmin) xmin=v;
    if(v>xmax) xmax=v;
  }
  mean = sum/n;
  stddev = sqrt(max(0.0, sumsq/n - (double)mean*mean));
  rms = sqrt(sumsq / n);
  ptp = xmax - xmin;
}

void setup(){
  Serial.begin(115200);
  pinMode(LED_POS, OUTPUT);
  pinMode(LED_NEG, OUTPUT);
  analogReadResolution(12);
  analogSetPinAttenuation(ADC_PIN, ADC_11db);
  Serial.println("# mean,std,rms,ptp,margin,y");
}

void loop(){
  collect_window(buf, N, FS_HZ);

  float mean, stddev, rms, ptp;
  calc_all(buf, N, mean, stddev, rms, ptp);

  double feats[4] = { (double)mean, (double)stddev, (double)rms, (double)ptp };
  double margin = score(feats);

  bool y = (margin >= 0.0);

  digitalWrite(LED_POS, y ? HIGH : LOW);
  digitalWrite(LED_NEG, y ? LOW  : HIGH);

  Serial.print(mean,5);  Serial.print(',');
  Serial.print(stddev,5);Serial.print(',');
  Serial.print(rms,5);   Serial.print(',');
  Serial.print(ptp,5);   Serial.print(',');
  Serial.print(margin,5);Serial.print(',');
  Serial.println((int)y);
}
