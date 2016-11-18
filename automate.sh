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
./main ../$INPUT_DIR/f1_dinv.txt ../$OUTPUT_DIR/f1_dinv_wt.txt
echo "[33%] f1_dinv_wt.txt"
./main ../$INPUT_DIR/f2.txt ../$OUTPUT_DIR/f2_wt.txt
echo "[66%] f2_wt.txt"
./main ../$INPUT_DIR/test.txt ../$OUTPUT_DIR/test_wt.txt
echo "[100%] test_wt.txt"

# Cleanup
cd ..
rm -r build
