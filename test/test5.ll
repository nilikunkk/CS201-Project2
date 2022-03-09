; ModuleID = 'test5.c'
source_filename = "test5.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @test5(i32 %a, i32 %b, i32 %c, i32 %d, i32 %e) #0 {
entry:
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %c.addr = alloca i32, align 4
  %d.addr = alloca i32, align 4
  %e.addr = alloca i32, align 4
  store i32 %a, i32* %a.addr, align 4
  store i32 %b, i32* %b.addr, align 4
  store i32 %c, i32* %c.addr, align 4
  store i32 %d, i32* %d.addr, align 4
  store i32 %e, i32* %e.addr, align 4
  %0 = load i32, i32* %b.addr, align 4
  %1 = load i32, i32* %c.addr, align 4
  %mul = mul nsw i32 %0, %1
  store i32 %mul, i32* %a.addr, align 4
  %2 = load i32, i32* %b.addr, align 4
  store i32 %2, i32* %d.addr, align 4
  %3 = load i32, i32* %a.addr, align 4
  %4 = load i32, i32* %b.addr, align 4
  %add = add nsw i32 %3, %4
  store i32 %add, i32* %c.addr, align 4
  %5 = load i32, i32* %d.addr, align 4
  %6 = load i32, i32* %c.addr, align 4
  %mul1 = mul nsw i32 %5, %6
  store i32 %mul1, i32* %e.addr, align 4
  %7 = load i32, i32* %c.addr, align 4
  %add2 = add nsw i32 %7, 5
  store i32 %add2, i32* %d.addr, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @test5(i32 1, i32 2, i32 3, i32 4, i32 5)
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"uwtable", i32 1}
!2 = !{i32 7, !"frame-pointer", i32 2}
!3 = !{!"clang version 13.0.0 (https://github.com/llvm/llvm-project/ 24c8eaec9467b2aaf70b0db33a4e4dd415139a50)"}
