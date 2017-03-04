make || exit 1
for file in *.c ; do
  base=${file%.*}
  clang-3.5 -g -c -emit-llvm $file -o $base.bc
  llvm-dis-3.5 $base.bc -o $base.ll
  opt-3.5 -load ./pass.so -def-pass $base.bc -o $base.def.bc 2> $base.def.out
  opt-3.5 -load ./pass.so -fix-pass $base.bc -o $base.fix.bc 2> /dev/null
  lli-3.5 $base.fix.bc > $base.fix.out
  diff $base.def $base.def.out > $base.def.diff
  if [ $? != 0 ]; then
	echo "Def diff for $base, see $base.def.diff"
  fi
  diff $base.fix $base.fix.out > $base.fix.diff
  if [ $? != 0 ]; then
	echo "Fix diff for $base, see $base.fix.diff"
  fi
done
