MoveOperation = {
    NoMove:0,
    Start:1,
    StartOfLine:3,
	StartOfBlock:4,
	StartOfWord:5,
	PreviousBlock:6,
	PreviousCharacter:7,
	PreviousWord:8,
	Up:2,
	Left:9,
	WordLeft:10,
	End:11,
	EndOfLine:13,
	EndOfWord:14,
	EndOfBlock:15,
	NextBlock:16,
	NextCharacter:17,
	NextWord:18,
	Down:12,
	Right:19,
	WordRight:20
}

MoveMode = {
	MoveAnchor:0,
	KeepAnchor:1
}

function RTF(ui)
{
	this.ui = ui;
	with (ui) {
		rtfEdit.insertHtml('<h1 align=center>БъЬт</h1>');
		rtfEdit.insertTable(4, 4);
//		rtfEdit.moveCursor(MoveOperation.StartOfLine, MoveOperation.MoveAnchor);
//		rtfEdit.moveCursor(MoveOperation.Up, MoveOperation.MoveAnchor);
//		rtfEdit.moveCursor(MoveOperation.Up, MoveOperation.MoveAnchor);
//		rtfEdit.moveCursor(MoveOperation.Up, MoveOperation.MoveAnchor);
	}
}
