# Navigation

- [1. Intro](#Intro)
- [2. Commands](#Commands)
- [3. Push swap and standart checker](#Push-swap-and-standart-checker)
	- [3.1. Install](##Install)
	- [3.2. Quick start](##Quick-start)
	- [3.3. Checker](##Checker)
	- [3.4. Delete](##Delete)
- [4. Checkers](#Checkers)
	- [4.1. PyChecker](##PyChecker)
	- [4.2. Tester](##Tester)

---
---

# Intro
Проект по моделированию сортировки двух стеков за минимальное количество итераций

---
---

# Commands
Примеры команд:

- pa - (push A) перекинуть из начала стека B в начало стека A
- pb - (push B) перекинуть из начала стека A в начало стека B
- sa - (swap A) поменять 2 первых элемента местами в стеке A
- sb - (swap B) поменять 2 первых элемента местами в стеке B
- ss - (swap A and B) выполнить swap стека A и B за 1 действие (тоже самое что и [sa, sb])
- ra - (rotate A) перекинуть из начала стека A в конец A
- rb - (rotate B) перекинуть из начала стека B в конец B
- rr - (rotate A and B) выполнить rotate стека A и B за 1 действие (тоже самое что и [ra, rb])
- rra - (reverse rotate A) перекинуть из конца стека A в начало стека A
- rrb - (reverse rotate B) перекинуть из конца стека B в начало стека B
- rrr - (reverse rotate A and B) выполнить reverse rotate стеков A и B за 1 действие (тоже самое что и [rra, rrb])

---
---

# Push swap and standart checker

## Install

Задите в директорию проекта и выполните команду:

		make

---

## Quick start

		ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG

---

## Checker

Flags:

-v - Визуализировать стеки

-с - Включить разные цвета

---

## Delete

Задите в директорию проекта и выполните команду:

		make fclean

---
---

# Checkers

## PyChecker
		ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | python3 ./checkers/PyChecker.py $ARG

---

## Tester
		python3 ./checkers/tester.py