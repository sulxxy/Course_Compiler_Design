# script for compiling
c_file_name="$1.c"
out_file_name="$1.out"
flex -o $c_file_name $1
gcc -o $out_file_name $c_file_name -lfl
