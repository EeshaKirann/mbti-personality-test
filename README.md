# MBTI Personality Type Test

A C++ console application that determines a user's MBTI personality type through an interactive 20-question quiz.

## How it works
- Users answer 20 questions on a 5-point agreement scale (Strongly Agree to Strongly Disagree)
- Each question contributes to one of 8 personality traits (E/I, S/N, T/F, J/P)
- The program calculates the dominant trait in each of the 4 categories
- Displays the resulting MBTI type along with a short personality description

## Concepts used
- Structures (`struct`) to model questions and traits
- Arrays for storing questions and scores
- Functions for modular program design
- Conditional logic for scoring and result generation

## How to run
1. Compile: `g++ mbti_test.cpp -o mbti_test`
2. Run: `./mbti_test`
3. Answer the prompts to get your MBTI result

## Team
Built as a Programming Fundamentals team project at Bahauddin Zakariya University.
