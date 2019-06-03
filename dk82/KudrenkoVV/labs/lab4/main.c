#include "tool.h"

void main() {
	FILE *fp;
	fopen_s(&fp, "Text.txt", "r+");
	List *list = readFile(fp);
	fclose(fp);

	fopen_s(&fp, "Text1.txt", "w+");
	outputElements(list->headNode, list->size, fp);
	fclose(fp);

	system("pause");
}