# C Scientific Calculator

A simple, menu-driven **scientific calculator** written in standard **C**.  
This program provides a command-line interface to perform various mathematical operations — from basic arithmetic to special functions.

---

## ✨ Features

This calculator includes a wide range of functions, categorized for ease of use.

---

### 🔹 Basic Operations (2 Inputs)
- Addition (`a + b`)
- Subtraction (`a - b`)
- Multiplication (`a * b`)
- Division (`a / b`)
- Power (`x^n`)

---

### 🔹 Standard Functions (1 Input)

#### **Logarithmic / Exponential**
- Exponential (`e^x`)
- Natural Log (`ln x`)

#### **Trigonometric** *(Input in Radians)*
- Sine (`sin x`)
- Cosine (`cos x`)
- Tangent (`tan x`)

#### **Inverse Trigonometric** *(Output in Radians)*
- Arcsine (`asin x`)
- Arccosine (`acos x`)
- Arctangent (`atan x`)

#### **Hyperbolic**
- Hyperbolic Sine (`sinh x`)
- Hyperbolic Cosine (`cosh x`)
- Hyperbolic Tangent (`tanh x`)

#### **Other**
- Square Root (`sqrt x`)
- Reciprocal (`1/x`)

---

### 🔹 Special Functions
- Gamma Function (`Γ(x)`)
- Error Function (`erf(x)`)
- Bessel Function (First Kind, `Jₙ(x)`)
- Legendre Polynomial (`Pₙ(x)`)
- Complex Exponential (`e^(ix)`) — uses `complex.h` to display results in **a + bi** form.

---

## ⚠️ A Note on Advanced Functions

Menu options such as **Derivative**, **Integral**, **Fourier Transform**, **Gradient**, **Divergence**, and **Curl** are **not implemented**.  
These operations differ fundamentally from numerical ones — they act on **entire functions or vector fields**, not on single numerical inputs.

Implementing them would require a **symbolic math engine** or **advanced numerical libraries**, which are beyond the scope of this simple calculator.  
The menu items are included to **explicitly indicate this limitation**.

---

## 🧩 How to Compile and Run

This program is written in **standard C**, relying on the **`math.h`** and **`complex.h`** libraries (C99 standard or later).

---

### 🧱 Compilation

Use `gcc` (or any compatible C compiler) to compile.  
You must link the math library using the `-lm` flag.

```bash
# Compile the C file and link the math library
gcc scientific_calculator.c -o calculator -lm
