# descend

Recurse from n down to 1, reporting each level to on\_enter on the way down and to on\_leave on the way back up

```c
void descend(int n, void (*on_enter)(int), void (*on_leave)(int))
```

**Difficulty:** 3/5
**Allowed functions:** none

Solved as level 2 of the c-structure-checkpoint challenge.
Validated 2 times. Earlier versions are in this file's git history.

[Read the full exercise on Grademe](https://grademe.io/app/exercise/recursion-trace)
