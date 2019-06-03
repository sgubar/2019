#include "tool.h"

void main() {
	FILE *fp;
	fopen_s(&fp, "Text.txt", "r+");
	List *list = readFile(fp);
	fclose(fp);

	fopen_s(&fp, "Text1.txt", "w+");
	doubleElement(list, 'q');
	printToFileList(fp, list);
	fclose(fp);

	system("pause");
}
