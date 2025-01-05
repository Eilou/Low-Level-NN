# Low Level Neural Network Attempt
*By Louie Brooks*

Basically this is my attempt to both learn C and my AI module by trying to create a very basic neural network in low level languages.

## Structure:
- 2 node input
- 1 hidden layer
    - 2 nodes
- 1 node output
- Full connected

![diagram structure](/diagram.png)

## Maths behind it
1. [Forward Pass](#forward-pass)
2. [Loss Function](#loss-function)
3. [Back Propagation](#back-propagation)
4. [Parameter Update](#parameter-update)

### Forward Pass

Note we must start with preset values for the following parameters:
$$
W_1, B_1, W_2, B_2
$$

Now we can do pass

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

Also worth noting that when we do the partial derivative of a transposed matrix, we drop the transposition in the coefficient (I think) because it now is unaffected by, in this case, the the matrix $A_1$

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

Because during the forward pass we do element-wise multiplication ($*$) during the linear transformation and the activation function, we must then do element-wise multiplication during backpropagation.

---

$$
\begin{aligned}
dW_1 &= \frac{\partial L}{\partial \hat{y}} \cdot \frac{\partial \hat{y}}{\partial net2} \cdot \frac{\partial net2}{\partial A_1} \cdot \frac{\partial A_1}{\partial net1} \cdot \frac{\partial net1}{\partial W_1} \\
&= dnet1 \cdot \frac{\partial net1}{\partial W_1} \\ \\ 
net1 &= W_1^T \cdot X + B_1\\
\frac{\partial net2}{\partial W_1} &= X \\ \\
dW_1 &= dnet1 \cdot X
\end{aligned}
$$

But again we need to transpose so the dimensions match

$$
\begin{aligned}
dW_1 &= X^T \cdot dnet1
\end{aligned}
$$

---

$$
\begin{aligned}
dB_1 &= \frac{\partial L}{\partial \hat{y}} \cdot \frac{\partial \hat{y}}{\partial net2} \cdot \frac{\partial net2}{\partial A_1} \cdot \frac{\partial A_1}{\partial net1} \cdot \frac{\partial net1}{\partial B_1} \\
&= dnet1 \cdot \frac{\partial net1}{\partial B_1} \\ \\ 
net1 &= W_1^T \cdot X + B_1\\
\frac{\partial net2}{\partial B_1} &= 1 \\ \\
dB_1 &= dnet1 \cdot 1 \\
&= dnet1
\end{aligned}
$$

---
### Parameter Update

$$
\begin{aligned}
\gamma &= \text{pre-set learning rate} \\ \\
W_1' &= W_1 - \gamma * dW_1 \\
B_1' &= B_1 - \gamma * dB_1 \\
W_2' &= W_2 - \gamma * dW_2 \\
B_2' &= B_2 - \gamma * dB_2 \\
\end{aligned}
$$

Could potentially adjust learning rate over time with reference to the number of generations ran through.

$$
\begin{aligned}
\gamma' = \frac{\gamma}{\text{number of iterations}}
\end{aligned}
$$


### [Back To Top](#low-level-neural-network-attempt)