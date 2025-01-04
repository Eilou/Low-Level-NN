# Low Level Neural Network Attempt
*By Louie Brooks*

Basically this is my attempt to both learn C and my AI module by trying to create a very basic neural network in low level languages.

## Initial structure:
- 2 node input
- 2 node hidden
- 1 node output
- Full connected

### Forward Pass
$$
\begin{aligned}
net1 &= W_1^T \cdot X + B_1 \\
A_1 &= \sigma(net1) \\
net2 &= W_2^T \cdot A_1 + B_2 \\
\hat{y} &= \sigma(net2)
\end{aligned}
$$

### Loss Function
In this I am going to be using the Square Loss Error function with the coefficient of $\large\frac{1}{2}$

$$
\begin{aligned}
L &= \frac{1}{2}(y-\hat{y})^2 \\
\frac{\partial L}{\partial \hat{y}} &= \hat{y} - y
\end{aligned}
$$

### Back Propagation
The change in each parameter, $\theta$, can be computed through the following equation

$$
\begin{aligned}
d\theta &= \frac{\partial L}{\partial \theta} \\
\theta' &= \theta - \gamma * d\theta
\end{aligned}$$

The maths I am going off for this program:

$$
\begin{aligned}
d\hat{y} &= \frac{\partial L}{\partial \hat{y}}
\end{aligned}
$$
---
$$
\begin{aligned}
dnet2 &= \frac{\partial L}{\partial \hat{y}} \cdot \frac{\partial \hat{y}}{\partial net2} \\
&= d\hat{y} \cdot \frac{\partial \hat{y}}{\partial net2} \\ \\
\hat{y} &= \sigma (net2) \\
\frac{\partial \hat{y}}{\partial net2} &= \sigma (net2) (1 - \sigma (net2)) \\
\frac{\partial \hat{y}}{\partial net2} &= \hat{y} (1 - \hat{y}) \\ \\
dnet2 &= d \hat{y} \cdot \hat{y}(1 -\hat{y})
\end{aligned}
$$
---
$$
\begin{aligned}
dW_2 &= \frac{\partial L}{\partial \hat{y}} \cdot \frac{\partial \hat{y}}{\partial net2} \cdot \frac{\partial net2}{\partial W_2} \\
&= dnet2 \cdot \frac{\partial net2}{\partial W_2} \\ \\
net2 &= W_2^T \cdot A_1 + B_2 \\
\frac{\partial net2}{\partial W_2} &= A_1 \\ \\
dW_2 &= A_1 \cdot dnet2^T
\end{aligned}
$$
---
$$
\begin{aligned}
dB_2 &= \frac{\partial L}{\partial \hat{y}} \cdot \frac{\partial \hat{y}}{\partial net2} \cdot \frac{\partial net2}{\partial B_2} \\
&= dnet2 \cdot \frac{\partial net2}{\partial B_2} \\ \\
net2 &= W_2^T \cdot A_1 + B_2 \\
\frac{\partial net2}{\partial B_2} &= 1 \\ \\
dB_2 &= dnet2 \cdot 1 \\
&= dnet2
\end{aligned}
$$
---
$$
\begin{aligned}
dA_1 &= \frac{\partial L}{\partial \hat{y}} \cdot \frac{\partial \hat{y}}{\partial net2} \cdot \frac{\partial net2}{\partial A_1} \\
&= dnet2 \cdot \frac{\partial net2}{\partial A_1} \\ \\
net2 &= W_2^T \cdot A_1 + B_2 \\
\frac{\partial net2}{\partial A_1} &= W_2 \\ \\

dA_1 &= dnet2 \cdot W_2
\end{aligned}
$$
But we can't do this because the dimensions don't match up. So instead we move about (and occasionally transpose) the matrices so they do actually match up.
$$
\begin{aligned}
dA_1 &= W_2 \cdot dnet2
\end{aligned}
$$
---
$$
\begin{aligned}
dnet1 &= \frac{\partial L}{\partial \hat{y}} \cdot \frac{\partial \hat{y}}{\partial net2} \cdot \frac{\partial net2}{\partial A_1} \cdot \frac{\partial A_1}{\partial net1} \\
&= dA_1 \cdot \frac{\partial A_1}{\partial net1} \\ \\ 
A_1 &= \sigma (net1) \\
\frac{\partial A_1}{\partial net1} &= \sigma(net1)(1-\sigma (net1)) \\
&= A_1(1- A_1) \\ \\
dnet1 &= dA_1 * A_1 *(1-A_1)
\end{aligned}
$$
Because during the forward pass we do element-wise multiplication during the linear transformation and the activation function, we must then do element-wise multiplication during backpropagation.

---
$$
\begin{aligned}