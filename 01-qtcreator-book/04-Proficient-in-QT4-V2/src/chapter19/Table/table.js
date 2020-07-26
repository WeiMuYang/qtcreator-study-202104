function Table(ui)
{
    this.ui = ui;

    with (ui) {
        btnClear.clicked.connect(this, tableWidget.clear);
        btnInsRow.clicked.connect(this, "insertRow");
        btnDelRow.clicked.connect(this, "deleteRow");
        btnInsCol.clicked.connect(this, "insertCol");
        btnDelCol.clicked.connect(this, "deleteCol");
    }
}

Table.prototype.insertRow = function()
{
	with (this.ui) {
	    tableWidget.insertRow(spinInsRow.value);
	}
}

Table.prototype.deleteRow = function()
{
	with (this.ui) {
    	tableWidget.removeRow(spinDelRow.value);
    }
}

Table.prototype.insertCol = function()
{
	with (this.ui) {
	    tableWidget.insertColumn(spinInsCol.value);
	}
}

Table.prototype.deleteCol = function()
{
	with (this.ui) {
		tableWidget.removeColumn(spinDelCol.value);
	}
}
