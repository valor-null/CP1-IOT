# IoT – Checkpoint 1
## 📌 Visão Geral:

**Lógica XOR no ESP32:**  
Foi feita a leitura de sinais no pino ADC (GPIO34) do ESP32. A cada janela de tempo, o código calculou valores como RMS (valor médio quadrático) e PTP (pico a pico). Esses valores foram comparados com limites (limiares) e transformados em dois sinais binários (A e B). A partir deles, foi implementada a operação XOR, que acende um LED quando a saída é verdadeira e outro LED quando é falsa.

**Dataset e Treinamento de Modelos:**  
Os dados coletados no ESP32 foram organizados em um arquivo CSV com as colunas: média (mean), desvio padrão (std), RMS (rms), pico a pico (ptp) e a classe (label). Esse dataset foi usado em Python para treinar dois modelos de Machine Learning: Decision Tree e SVM. Depois do treinamento, os modelos foram avaliados (Accuracy, F1-score, matriz de confusão) e exportados em C (model_dt.c e model_svm.c) para poderem ser usados no microcontrolador.

## 🧠 **Modelo escolhido:**  
Escolhemos o modelo Linear SVM como final. Nos testes, ele teve um desempenho mais equilibrado para diferenciar quando havia atividade (label=1) e quando não havia (label=0). Apesar de a árvore de decisão ter uma acurácia parecida, o SVM conseguiu identificar melhor os casos positivos. Além disso, ele gera um código em C simples, que facilita a integração no ESP32.

## ▶️ **Como rodar**  

**Parte 1 — XOR (ESP32):**  
Abra `/parte1/codigo.ino` no Arduino IDE.  

Pinos:  
- Sensor/Pot: GPIO34 (ADC)  
- LEDs: GPIO2 e GPIO4, cada um em série com resistor (~220 Ω) ao GND  

Faça upload e gire o potenciômetro/sensor → os LEDs alternam conforme Y = A ⊕ B.  

**Parte 2 — Treinamento (Python):**  
Entre na pasta `/parte2/` e garanta que o arquivo `dataset_features.csv` está lá.  

Instale dependências:  
```bash
pip install -U pandas scikit-learn m2cgen
```

Execute:  
```bash
python train_models.py
```

Serão gerados automaticamente:  
- `model_dt.c`  
- `model_svm.c`

## 👥 Integrantes  
- Valéria Conceição Dos Santos -- RM: 557177  
- Guilherme Romanholi Santos -- RM: 557462  
- Erick Alves Xavier Dos Santos -- RM: 556862  
- Luiz Eduardo Da Silva Pinto -- RM: 555213  
- Mirela Pinheiro Silva Rodrigues -- RM: 558191  
