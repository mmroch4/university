start_h = int(input())
start_m = int(input())
start_s = int(input())

baking_h = int(input())
baking_m = int(input())
baking_s = int(input())

final_h = start_h + baking_h
final_m = start_m + baking_m
final_s = start_s + baking_s

if final_s >= 60:
  surplus = final_s // 60
  final_m += surplus
  final_s -= surplus * 60

if final_m >= 60:
  surplus = final_m // 60
  final_h += surplus
  final_m -= surplus * 60
  
if final_h >= 24:
  surplus = final_h // 24
  final_h -= surplus * 24
  
def padLeft(string, l, c):
  if len(string) < l:
    return (c * (l - len(string))) + string
  
  return string
  
final_h = padLeft(str(final_h), 2, "0")
final_m = padLeft(str(final_m), 2, "0")
final_s = padLeft(str(final_s), 2, "0")

print(f"Take the cake out at {final_h}:{final_m}:{final_s}.")