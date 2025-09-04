#include <string.h>
void score(double * input, double * output) {
    double var0[2];
    if (input[0] <= 0.27792999148368835) {
        if (input[3] <= 0.12075500190258026) {
            if (input[3] <= 0.07533499971032143) {
                memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
            } else {
                memcpy(var0, (double[]){0.28125, 0.71875}, 2 * sizeof(double));
            }
        } else {
            if (input[0] <= 0.07135999947786331) {
                memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
            } else {
                memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
            }
        }
    } else {
        if (input[1] <= 0.15687000006437302) {
            if (input[3] <= 0.42759500443935394) {
                if (input[3] <= 0.38009999692440033) {
                    if (input[0] <= 0.5153049826622009) {
                        if (input[0] <= 0.35849499702453613) {
                            memcpy(var0, (double[]){0.43902439024390244, 0.5609756097560975}, 2 * sizeof(double));
                        } else {
                            memcpy(var0, (double[]){0.11538461538461539, 0.8846153846153847}, 2 * sizeof(double));
                        }
                    } else {
                        if (input[0] <= 0.9696399867534637) {
                            if (input[1] <= 0.1034649983048439) {
                                memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
                            } else {
                                memcpy(var0, (double[]){0.28125, 0.71875}, 2 * sizeof(double));
                            }
                        } else {
                            if (input[3] <= 0.10451500117778778) {
                                if (input[0] <= 0.9986899793148041) {
                                    memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
                                } else {
                                    memcpy(var0, (double[]){0.43902439024390244, 0.5609756097560975}, 2 * sizeof(double));
                                }
                            } else {
                                if (input[0] <= 0.9853050112724304) {
                                    memcpy(var0, (double[]){0.43902439024390244, 0.5609756097560975}, 2 * sizeof(double));
                                } else {
                                    memcpy(var0, (double[]){0.0, 1.0}, 2 * sizeof(double));
                                }
                            }
                        }
                    }
                } else {
                    if (input[2] <= 0.5843999981880188) {
                        memcpy(var0, (double[]){0.28125, 0.71875}, 2 * sizeof(double));
                    } else {
                        memcpy(var0, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 0.1343500018119812) {
                    memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
                } else {
                    memcpy(var0, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            }
        } else {
            if (input[2] <= 0.6294049918651581) {
                memcpy(var0, (double[]){0.43902439024390244, 0.5609756097560975}, 2 * sizeof(double));
            } else {
                if (input[3] <= 0.5264950096607208) {
                    memcpy(var0, (double[]){0.16363636363636366, 0.8363636363636364}, 2 * sizeof(double));
                } else {
                    memcpy(var0, (double[]){0.0, 1.0}, 2 * sizeof(double));
                }
            }
        }
    }
    memcpy(output, var0, 2 * sizeof(double));
}
