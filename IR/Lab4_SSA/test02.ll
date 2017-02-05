; ModuleID = 'test02.bc'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [13 x i8] c"%d %d %f %f\0A\00", align 1

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = add nsw i32 2, 3
  %2 = icmp slt i32 2, 3
  %3 = zext i1 %2 to i32
  %4 = sitofp i32 2 to float
  %5 = sitofp i32 2 to float
  %6 = fmul float %5, 0x40091EB860000000
  %7 = fpext float %4 to double
  %8 = fpext float %6 to double
  %9 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([13 x i8]* @.str, i32 0, i32 0), i32 %1, i32 %3, double %7, double %8)
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"}
