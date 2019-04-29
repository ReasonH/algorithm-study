#include <stdio.h>
#include <string>
using namespace std;

bool arr[21];
int main()
{
	fill(arr, arr + 21, false);
	int command_size;
	string command;
	scanf_s("%d", &command_size);
	while (command_size--)
	{
		int num;
		char commandread[7];
		scanf_s("%6s", commandread, 7);
		scanf_s("%d", &num);
		command = commandread;
		if (command == "add")
		{
			if(!arr[num])
				arr[num] = true;
		}
		else if (command == "remove")
		{
			if (arr[num])
				arr[num] = false;
		}
		else if (command == "check")
		{
			if (arr[num])
				printf("1\n");
			else
				printf("0\n");
		}
		else if (command == "toggle")
		{
			if (arr[num])
				arr[num] = false;
			else
				arr[num] = true;
		}
		else if (command == "all")
		{
			fill(arr, arr + 21, true);
		}
		else if (command == "empty")
		{
			fill(arr, arr + 21, false);
		}
	}
	return 0;
}