import pandas as pd
import numpy as np
from collections import Counter
from sklearn.model_selection import train_test_split, cross_val_score, StratifiedKFold
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import LinearSVC
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import m2cgen as m2c

CSV_PATH = "dataset_features.csv"
FEATURES = ["mean","std","rms","ptp"]
TARGET = "label"

df = pd.read_csv(CSV_PATH)
df = df.dropna()
df[TARGET] = df[TARGET].astype(int)
df = df.drop_duplicates()

mask_sat = (df["mean"].round(5)==1.0) & (df["std"].round(5)==0.0) & (df["rms"].round(5)==1.0) & (df["ptp"].round(5)==0.0)
df_sat = df[mask_sat]
df_nsat = df[~mask_sat]
if not df_sat.empty:
    keep_n = int(len(df_nsat)*0.15) if len(df_nsat)>0 else 0
    df_sat = df_sat.sample(n=min(len(df_sat), max(5, keep_n)), random_state=42)
    df = pd.concat([df_nsat, df_sat], ignore_index=True)

X = df[FEATURES].values.astype(np.float64)
y = df[TARGET].values.astype(int)

print("Amostras após limpeza:", X.shape[0])
print("Distribuição de classes:", Counter(y))
print(df.head())

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, stratify=y, random_state=42
)
skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

dt = DecisionTreeClassifier(min_samples_leaf=3, class_weight="balanced", random_state=42)
cv_dt = cross_val_score(dt, X_train, y_train, cv=skf)
dt.fit(X_train, y_train)
y_pred_dt = dt.predict(X_test)
print("\n=== Decision Tree ===")
print("CV acc média:", cv_dt.mean().round(3))
print("Teste acc:", round(accuracy_score(y_test, y_pred_dt), 3))
print(classification_report(y_test, y_pred_dt, digits=3))
print("Matriz de confusão:\n", confusion_matrix(y_test, y_pred_dt))

svm = LinearSVC(C=1.0, class_weight="balanced", random_state=42, max_iter=10000)
cv_svm = cross_val_score(svm, X_train, y_train, cv=skf)
svm.fit(X_train, y_train)
y_pred_svm = svm.predict(X_test)
print("\n=== Linear SVM ===")
print("CV acc média:", cv_svm.mean().round(3))
print("Teste acc:", round(accuracy_score(y_test, y_pred_svm), 3))
print(classification_report(y_test, y_pred_svm, digits=3))
print("Matriz de confusão:\n", confusion_matrix(y_test, y_pred_svm))

open("model_dt.c", "w").write(m2c.export_to_c(dt))
open("model_svm.c", "w").write(m2c.export_to_c(svm))
print("\nGerado: model_dt.c e model_svm.c")
