#include "rtfedit.h"

RTFEdit::RTFEdit(QWidget *parent)
	: QTextEdit(parent)
{
	
}

void RTFEdit::insertTable(int row, int col)
{
	QString htm("<table border=1 width=100%>");
	for(int i=0; i<row; i++)
	{
		htm += "<tr>";
		for(int j=0; j< col; j++)
		{
			htm += "<td> </td>";
		}	
		htm += "</tr>";
	}
	htm += "</table>";
	insertHtml(htm);
}

void RTFEdit::moveCursor(int operation, int mode)
{
	moveCursor(operation, mode);
}