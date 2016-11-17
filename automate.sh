# Define useful directories
INPUT_DIR="input"
OUTPUT_DIR="output"
SRC_DIR="src"

# Build project
mkdir -p build
cd build
cmake ../$SRC_DIR
make

# Run project
echo ""
./main ../$INPUT_DIR/f1_dinv.txt ../$OUTPUT_DIR/f1_dinv_output.txt
echo "[33%] f1_dinv_output.txt"
./main ../$INPUT_DIR/f2.txt ../$OUTPUT_DIR/f2_output.txt
echo "[66%] f1_output.txt"
./main ../$INPUT_DIR/test.txt ../$OUTPUT_DIR/test_output.txt
echo "[100%] myimage_output.txt"
# Cleanup
cd ..
rm -r build
