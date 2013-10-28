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
}

/*
void printString(int ln, int col, char* message)
{
	return;
}
*/

void clearScreen()
{
	int i = 0;

	for (i=memoryBase; i+=2; i<screenCharCount)
	{
		putInMemory(segmentBase, i, ' ');
		putInMemory(segmentBase, i+1, colorWhite);
	}

	putInMemory(segmentBase, memoryBase, 'A');
	putInMemory(segmentBase, memoryBase + 1, colorWhite);

	return;
}