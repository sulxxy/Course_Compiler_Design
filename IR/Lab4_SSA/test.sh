LLVM_VERSION=3.5
make LLVM_VERSION=$LLVM_VERSION || exit 1
for file in *.c ; do
  base=${file%.*}
  clang-$LLVM_VERSION -c -emit-llvm $file -o $base.bc
  opt-$LLVM_VERSION -mem2reg $base.bc -o $base.bc
  llvm-dis-$LLVM_VERSION $base.bc -o $base.ll
  opt-$LLVM_VERSION -load ./pass.so -const-prop-pass $base.bc > /dev/null 2> $base.out
  diff $base.exp $base.out > $base.diff
  if [ $? != 0 ]; then
	echo "Output diff for $base, see $base.diff"
  fi
done
