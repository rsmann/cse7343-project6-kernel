/* Kernel.c
 * Scott Mann
 * CSE 7343
 * A Simple Kernel that prints "Hello World" at the top-left corner of the screen.
 * Judging from the comments on Piazza, I did more than expected by flushing the memory (yay!)
 */

/* Function Prototypes */
void printString(int ln, int col, int color, char* message);
void printHelloWorld();
void clearScreen();
void printEnd();

/* Some pseudo-constants (since I'm unsure of K&R C requirements)
 * for use in calculations in other functions involving memory offsets
 */
int columnCount = 80;
int rowCount = 25;
int screenCharCount = 2000; /* 80x25 */
int colorWhite = 0x7;

int segmentBase = 0xB000;
int memoryBase = 0x8000;
int videoMemoryBase = 0xB8000;

/* The main entry point of the program */
int main()
{
	clearScreen();
	printHelloWorld();
	/*printString(5, 5, 0x7, "Testing...");*/

	/* Print "End" on the last line of the screen to show when
	 * execution reaches this point and we go into the loop. 
	 */
	printEnd();

	/* Infinite Loop (not the one in Cupertino) */
	while (1==1) {}
}

/* This function prints "End" at the bottom left corner of the screen. */
void printEnd()
{
	putInMemory(segmentBase, memoryBase + 3840, 'E');
	putInMemory(segmentBase, memoryBase + 3841, colorWhite);

	putInMemory(segmentBase, memoryBase + 3842, 'n');
	putInMemory(segmentBase, memoryBase + 3843, colorWhite);

	putInMemory(segmentBase, memoryBase + 3844, 'd');
	putInMemory(segmentBase, memoryBase + 3845, colorWhite);

}

/* This function accepts a line, column, color, and string and outputs the message
 * at the specified coordinates.
 * That was the goal anyway, I didn't get to fully test it out and resolve my
 * math errors.
 */
void printString(int ln, int col, int color, char* message)
{
	int relativeAddress = 0;
	int len = 0;
	int i = 0;

	/* Calculate the relative address in memory*/
	relativeAddress = ((columnCount * (ln-1)) * 2); /* + (col*2));*/
	
	/* Hard code relative address for testing */
	relativeAddress = 160;

	/* Calculate the length of the message */
	/*len = sizeof(message2)/sizeof(char);*/

	/* Hard coded for testing */
	len = 12;

	/* Loop through each character in the specified message and 
	 * output it in the specified color, beginning at the specified coordinates.
	 * That was the plan, didn't get all the way finished.
	 */

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

/* Prints "Hello World" at the top left corner of the screen the "cheap" way
 * I wanted to use the above function to print anything anywhere. Out of time.
 */
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
}

/* Zeroes out the memory and blanks out the screen. */
void clearScreen()
{
	int i = 0;
	int j = 0;

	/* Iterate through each character position and null it out and 
	 * default the color code to white.
	 */
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
