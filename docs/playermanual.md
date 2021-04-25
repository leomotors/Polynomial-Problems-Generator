# Player Manual

For Interactive Mode, get an experience of playing a game!

## Mode

There is 3 Modes in this game

In all mode you can choose degree of Polynomial (called Difficulity)

Recommends are 2 and 3, you don't want to go beyond degree 3, trust me.

### Test Mode

Extra Arguments: Number of Questions

You do a simulation test with number of questions you entered.

Try to Score 100%!

### Endless Mode

Until you answer wrong, the game goes on and on!

### Time Limit Mode

You have limited time to answer at most question as possible!

However since this is C++ and I don't wanna dig deep into async stuff there is
extra injury time for you until you finish last question!

## How to Answer

You don't need to answer them in any order, but you must answer all of them.

Since you are solving the equation, duplicate answer will be result in wrong.

It is guarantee that all answer is real.

To answer, enter all roots seperated by space bar.

If the answer is fraction answer it in form of a/b where a,b is integer, b > 0

### Example

```
>> Solve (x-3)(x+4) = 0
>> 3 -4
>> -4 3
Both are acceptable.
```

```
>> Solve (2x-3)(3x+5) = 0
>> 3/2 -5/3
>> -5/3 3/2
Both are acceptable.
```

```
>> Solve (x-1)(x-1)(x+2) = 0
>> 1 -2
>> -2 1
>> 1 1 -2
Only the first 2 are acceptable.
```
