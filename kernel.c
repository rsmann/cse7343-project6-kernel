/* Kernel.c
 * Scott Mann
 * CSE 7343
 * A Simple Kernel that prints "Hello World" at the top-left corner of the screen.
 
void printString(int ln, int col, char* message);
*/

void clearScreen();

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
}

/*
void printString(int ln, int col, char* message)
{
	return;
}
*/

void printHelloWorld()
{
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
}

void clearScreen()
{
	int i = memoryBase;

	/*
	for (i=memoryBase; i+=2; i<screenCharCount*2)
	{
		putInMemory(segmentBase, i, 'A');
		putInMemory(segmentBase, i+1, colorWhite);
	}
	*/



	/*
	putInMemory(0xB000, 0x8140, 'A');
	putInMemory(0xB000, 0x8141, 0x7);
	*/
	return;
}