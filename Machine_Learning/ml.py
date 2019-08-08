def softmax(x):
    """ Softmax function """
    return x.exp() / np.sum(x.exp())

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

def comp_iou(r1, r2):
    """ rec: (y0, x0, y1, x1) """
    s1 = (r1[3]-r1[1])*(r1[2]-r1[0])
    s1 = (r2[3]-r2[1])*(r2[2]-r2[0])
    s_sum = s1+s2

    left = max(r1[1], r2[1]) ## intersect's left, is the rightmost x0
    right = min(r1[3], r2[3]) ## intersect's right, is the leftmost x1
    top = max(r1[0], r2[0]) ## intersect's top, is the bottom y0
    bottom = min(r1[2], r2[2]) ## intersect's bottom, is the top of y1

    if left>=right or top>=bottom:
        return 0 ## No overlap
    else:
        intercept = (right-left)*(bottom-top)
        return intercept / (s_sum-intercept)
