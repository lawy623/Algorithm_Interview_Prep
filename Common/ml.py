def softmax(x):
    """ Softmax function """
    return x / np.sum(x.exp())

def softmax_modify(x):
    """ the input x may be too large. """
    x = x - x.max()
    return softmax(x)

def cross_entropy(y_hat, y):
    """ cross entropy loss """
    return -y_hat.take(y).log()

def cross_entropy_modify(y_hat,y):
    """ y_hat at y may be zero """
    return cross_entropy(y_hat+1e-5, y)

def accuracy(y_hat, y):
    """ accuracy of classification """
    return np.mean(y_hat.argmax(y) == y)

def corr2d(X, K):
	h, w = K.shape
	Y = nd.zeros((X.shape[0]-h+1, X.shape[1]-w+1))
	for i in range(Y.shape[0]):
		for j in range(Y.shape[1]):
			Y[i,j] = (X[i:i+h, j:j+w]).sum()
	return Y
