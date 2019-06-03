#include "tree.h"
#define MAXSIZE 5

void debugTree(BinTree *ATree);
void symmTree(BinTree *ATree);
void randTree(BinTree *ATree);

int main(int argc, char **argv)
{
	srand(time(NULL));
	
	//making a tree
	BinTree *ATree = createBinTree();
	
	debugTree(ATree);
	//symmTree(ATree);
	//randTree(ATree);
	
	initscr();
	
	if(has_colors() == FALSE)
	{	
		endwin();
		printf("Your terminal does not support color.\n");
	}
	start_color();
	
	int x, y, toDelete = 0;
	const char *input_mesg = "Value to delete?";
	const char *continue_mesg = "Press Enter to continue or Escape to exit.";
	
	getmaxyx(stdscr, y, x);
	
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	
	char ch = 'a';
	while (ch != 27 && NULL != ATree->root) //27 is an escape key
	{
		clear();
		attron(COLOR_PAIR(1) | A_BOLD);	
		drawBinTree(ATree->root, x/2, y - y, x/2);
		attroff(COLOR_PAIR(1) | A_BOLD);
		refresh();
		
		curs_set(1);
		echo();
		mvprintw(y - 2, (x - strlen(input_mesg))/2, "%s", input_mesg);
		mvscanw(y - 1, x/2, "%d", &toDelete);
		curs_set(0);
		noecho();
	
		ATree->root = destroyTreeNode(ATree->root, toDelete);
		
		clear();
		attron(COLOR_PAIR(2) | A_BOLD);	
		drawBinTree(ATree->root, x/2, y - y, x/2);
		attroff(COLOR_PAIR(2) | A_BOLD);
		refresh();
		
		mvprintw(y - 2, (x - strlen(continue_mesg))/2, "%s", continue_mesg);
		ch = getch();
	}
	endwin();
	
	/*printBinTree(ATree->root);
	
	if (NULL != findNode(ATree, 16))
		printf("%d\n", findNode(ATree, 16)->value);
	else
		printf("Node not found.\n");*/

	destroyBinTree(ATree);
	
	return 0;
}

void debugTree(BinTree *ATree)
{
	addNode(ATree, 15);
	addNode(ATree, 5);
	addNode(ATree, 17);
	addNode(ATree, 16);
	addNode(ATree, 2);
	addNode(ATree, 10);
	addNode(ATree, 19);
}

void symmTree(BinTree *ATree)
{
	addNode(ATree, 5);
	
	addNode(ATree, 4);
	addNode(ATree, 3);
	addNode(ATree, 2);
	addNode(ATree, 1);
	addNode(ATree, 0);
	addNode(ATree, 6);
	addNode(ATree, 7);
	addNode(ATree, 8);
	addNode(ATree, 9);
	
	addNode(ATree, 1);
	addNode(ATree, 2);
	addNode(ATree, 3);
	addNode(ATree, 4);
	addNode(ATree, 5);
	addNode(ATree, 6);
	addNode(ATree, 7);
	addNode(ATree, 8);
	addNode(ATree, 9);
}

void randTree(BinTree *ATree)
{
	for (int i = 0; i < MAXSIZE; i++)
		addNode(ATree, 0 + rand() % 10);
}
