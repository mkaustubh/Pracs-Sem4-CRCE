#! /bin/bash
echo "SOURCE DIR"
read SRC_DIR
echo "DESTINATION DIR"
read DST_DIR
echo "FILE NAME"
read FILEN
echo "RENAME IT TO :"
read RENAM

cp "$SRC_DIR/$FILEN" "$DST_DIR/$RENAM"
