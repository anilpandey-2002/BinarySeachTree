
void nextGreatest(int arr[], int size)
{
	int max_from_right = arr[size - 1];
	arr[size - 1] = -1;

	for (int i = size - 2; i >= 0; i--)
	{
		int temp = arr[i];
		arr[i] = max_from_right;
		max_from_right = max(max_from_right, temp);
	}
}
