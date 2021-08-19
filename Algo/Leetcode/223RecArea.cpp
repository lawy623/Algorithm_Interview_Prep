class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int right = min(ax2, bx2);
        int left = max(ax1, bx1);
        int up = min(ay2, by2);
        int low = max(ay1, by1);
        int iou = 0;
        if(right > left && up > low) iou = (right-left)*(up-low);
        int s1 = (ax2-ax1) * (ay2-ay1);
        int s2 = (bx2-bx1) * (by2-by1);
        return s1+s2 - iou;
    }
};