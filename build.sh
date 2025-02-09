#!/bin/sh

# Settings
BINARY="bstd"
TARGET_DIR="./target"
SRC_DIR="./src"
LIBRARIES=()

# Create output directory if it doesn't exist
mkdir -p "$TARGET_DIR"

# Clean files inside target directory
rm -f "$TARGET_DIR/"*

# Find all .c files in the source path
FILES=$(find "$SRC_DIR" -name "*.c" | paste -sd " ")

# Prepare library arguments
LIBRARIES_ARGS=""
for LIB in "${LIBRARIES[@]}"; do
    LIBRARIES_ARGS="$LIBRARIES_ARGS -l$LIB"
done

# Compile
if [ -n "$FILES" ]; then
    gcc $FILES $LIBRARIES_ARGS -o "$TARGET_DIR/$BINARY" || exit 1
else
    echo "No source files found in $SRC_DIR."
    exit 1
fi

echo "Build completed successfully. Executable: $TARGET_DIR/$BINARY"
