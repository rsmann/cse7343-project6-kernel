/* Kernel.c
 * Scott Mann
 * CSE 7343
 * A Simple Kernel that prints "Hello World" at the top-left corner of the screen.
*/

void printString(int ln, int col, int color, char* message);
void printHelloWorld();
void clearScreen();
void printEnd();

int columnCount = 80;
int rowCount = 25;
int screenCharCount = 2000; /* 80x25 */
int colorWhite = 0x7;

int segmentBase = 0xB000;
int memoryBase = 0x8000;
int videoMemoryBase = 0xB8000;

int main()
{
	clearScreen();
	printHelloWorld();
	/*printString(5, 5, 0x7, "Testing...");*/

	printEnd();

	while (1==1) {}
}

void printEnd()
{
	putInMemory(segmentBase, memoryBase + 3840, 'E');
	putInMemory(segmentBase, memoryBase + 3841, colorWhite);

	putInMemory(segmentBase, memoryBase + 3842, 'n');
	putInMemory(segmentBase, memoryBase + 3843, colorWhite);

	putInMemory(segmentBase, memoryBase + 3844, 'd');
	putInMemory(segmentBase, memoryBase + 3845, colorWhite);

}
void printString(int ln, int col, int color, char* message)
{
	int relativeAddress = 0;
	int len = 0;
	int i = 0;

	relativeAddress = ((columnCount * (ln-1)) * 2); /* + (col*2));*/
	relativeAddress = 160;
	/*len = sizeof(message2)/sizeof(char);*/
	len = 12;

	putInMemory(segmentBase, relativeAddress, 'B');
	putInMemory(segmentBase, relativeAddress + 2, 'o');
	putInMemory(segmentBase, relativeAddress + 4, 'o');

	/*

	while (i < len)
	{
		putInMemory(segmentBase, relativeAddress + i, *message2[i/2]);
		putInMemory(segmentBase, relativeAddress + i + 1, color);

		i = i + 2;
	}
*/

	return;
}

void printHelloWorld()
{
	int j = 0;

	putInMemory(segmentBase, memoryBase, 'H');
	putInMemory(segmentBase, memoryBase + 1, colorWhite);

	putInMemory(segmentBase, memoryBase + 2, 'e');
	putInMemory(segmentBase, memoryBase + 3, colorWhite);

	putInMemory(segmentBase, memoryBase + 4, 'l');
	putInMemory(segmentBase, memoryBase + 5, colorWhite);

	putInMemory(segmentBase, memoryBase + 6, 'l');
	putInMemory(segmentBase, memoryBase + 7, colorWhite);

	putInMemory(segmentBase, memoryBase + 8, 'o');
	putInMemory(segmentBase, memoryBase + 9, colorWhite);

	putInMemory(segmentBase, memoryBase + 10, ' ');
	putInMemory(segmentBase, memoryBase + 11, colorWhite);

	putInMemory(segmentBase, memoryBase + 12, 'W');
	putInMemory(segmentBase, memoryBase + 13, colorWhite);

	putInMemory(segmentBase, memoryBase + 14, 'o');
	putInMemory(segmentBase, memoryBase + 15, colorWhite);

	putInMemory(segmentBase, memoryBase + 16, 'r');
	putInMemory(segmentBase, memoryBase + 17, colorWhite);

	putInMemory(segmentBase, memoryBase + 18, 'l');
	putInMemory(segmentBase, memoryBase + 19, colorWhite);

	putInMemory(segmentBase, memoryBase + 20, 'd');
	putInMemory(segmentBase, memoryBase + 21, colorWhite);

	putInMemory(segmentBase, memoryBase + 22, '!');
	putInMemory(segmentBase, memoryBase + 23, colorWhite);

	/* Delay before returning to allow the screen to catch up */
	/*
	for (j=0; j++; j<1000)
	{

	}
	*/
}

void clearScreen()
{
	int i = 0;
	int j = 0;

	while (i < screenCharCount*2)
	{
		putInMemory(segmentBase, memoryBase + i, '\0');
		putInMemory(segmentBase, memoryBase + i + 1, colorWhite);

		i=i+2;
	}

	/* Delay before returning to allow the screen to catch up */
	for (j=0; j++; j<100)
	{

	}

	return;
}
