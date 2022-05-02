# Philosophers

It's the perfect time now to start working with multi threading, because as you may already know, we already been working with thread but it was only one at time.

## Multithreading

Multithreading is basically splitting machine resources (`CPU cores`), so we can do more tasks at the same time (`it saves time`),
How is that ?. let's say that you have a routine, and this last needs be done 3 times, and each time uses diffrent input so! the output is obviously not gonna be the same.

Well the solution is just to iterate that routine 3 times and you gonna be just fine, but wait we have a problem, it seems that this solution was quick. no its not (specially in some cases where we don't know where the routine is gonna end).

What we do ? we run them all at once, each one in a `thread` and we wait for them until they end, we process their output.

see its that easy.

## Philosophers

`Philosophers` is a common problem in computer science, that helps us getting into multithreading programing.

The problem is that we have some stupid philosophers sitting around a table, each one of them with only one fork (the forks are all at the table), the routine is that each one of them should not die (`starving`), so they should eat.

They need to use two `forks`, since they have only one, each one gonna take his neighbor's fork (if that neighbor is not using it).

If they couldn't eat they think (what other thing a philosopher can do!), until they get to eat or they die starving.

After eating what's better than taking a nap, they go to bed, take a good nap, when they wake up they start thinking and they wait for the forks to be ready, so they can eat again, and so on so forth....

This life cycle have factors : time to eat, time to die and time to sleep, the most important one of them, is time to die because if a philosopher past that time befor start eating again they die.

## Mutex

The mutex is like a lock we use it to protect a part of our code, that we want to be executed by one thread at a time.

Let's say we have memory address, that the threads share, and all of them want to write something to it, without locks things will get messy.

Will happen what's called data race, so keep your data safe and use mutex.

## Hint

*Think of a fork as a mutex (each philosopher should have the mutex's adress of his neighbor)

*I have no other hints

## Resouces

https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-pthread-create-create-thread

https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
