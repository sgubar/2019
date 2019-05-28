
void qs(char *a, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = a[(left + right) / 2];
		do
		{
			while (a[left] > middle) left++;
			while (a[right] < middle) right--;
			if (left <= right)
			{
				char t = a[left];
				a[left] = a[right];
				a[right] = t;
				left++;
				right--;
			}
		} while (left <= right);
		qs(a, first, right); // рекурсивный вызов
		qs(a, left, last);
	}
}


void quics(char *a, int n) {
	qs(a, 0, n - 1);
}


int linsearch(char c,  char *a, int n) {
	int res = -1, i;
	for (i = 0; i < n - 1; i++) {
		if (a[i] == c) {
			res = i;
			break;
		}
	}
	return res;
}





