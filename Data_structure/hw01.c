int lsc_cross(char* A, int p, int m, int r) {
     int lsc = 0, i;
     for (i = m; i >= p; i--)
        if (A[i] == A[m]) lsc++;
       else break;
     for (i = m + 1; i <= r; i++)
        if (A[i] == A[m]) lsc++;
		else break;
     return lsc;
}

int lsc(char* A, int p, int r) {

     if (p == r) return 1;
     else {
         int mid = (p + r) / 2;
         int left = lsc(A, p, mid);
         int right = lsc(A, mid + 1, r);
         int cross = lsc_cross(A, p, mid, r);

         if (left >= right && left >= cross) return left;
         else if (right >= left && right >= cross) return right;
         else return cross;

	}
}