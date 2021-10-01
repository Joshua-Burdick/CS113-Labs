# CS113-Labs
My .cpp files for CS113 Labs at SNHU.

## Lab 1
The first piece of the lab is a simple print statement that prints ``"Hello World!"``.

The second piece is simple character art, using multiple print statements and escape characters to display the art.

The final section of the lab is squaring a number taken in as input (through ``cin``). Then, my solution uses the ``pow(a, b)`` function to square the input number.
The first parameter is the base, and the second is the exponent. Finally, the program prints ``The number squared:``, followed by the previously calculated square.

## Lab 2
The first problem in Lab 2 is a coin calculator. The program takes in a number of quarters, dimes, and nickels. Then, each number is multiplied by 25, 10, and 5 respectively, and the resultant sum is the total amount, in cents.

The second part is also a coin calculator, but in reverse. Given a total number of cents, the program uses modulo and subtraction to determine the number of each coin (from half dollars down to pennies) required to reach the total amount of cents.

Part 3 is a simple Fahrenheit to Celsius converter. Using the formula ``C = (F - 32) * (5/9)``, upon taking in a Fahrenheit temperature as a _double_ (to account for floating point values of degrees), that number is passed into the above equation and evaluated. This number is then printed to the screen, using `` << fixed << setprecision(2) << `` on the cout statements so that each printed result will be shown with 2 decimal places.

## Lab 3
Problem 1 in Lab #3 computes the time (in minutes) to mow a lawn given the dimensions of a lawn and of a house. Note that these equations assume that the lawn and the house are rectangular in shape. The length and width of the lawn and house are multiplied together to find the area, and then the area of the house is subtracted from the area of the lawn to find the area to be mowed. From there, the area to be mowed is divide by 7 (since the problem assumes the lawn is mown at 7 square feet per second). In one final step, this new number is divided by 60, to convert the rate in seconds into minutes, and that value is then printed to the console.

Problem #2 Is a physics simulation, using the formula ``-16t^2 + v0*t + h0``. With an initial velocity in ft/s, initial height off the ground in ft, and time elapsed in s, these numbers are substituted in and the height of the ball after _t_ seconds is calculated. This is then done twice more, but with _t_ + 1 and _t_ + 2 seconds. All three results are printed to the console in the final output, to 2 decimal places since the inputs were taken with doubles.

## Lab 4
Lab 4 is a bill calculator for a party. First, the program prompts the user for the number of beef meals and vegan meals, respectively. Then, the sum of those two numbers yields the number in the party, which can be used to calculate which room will be used (and thus the room charge). Room 1 seats 200, Room 2 seats 100, and Room 3 seats 50; using conditionals to detect if the number is higher then the number a room can seat, the room cost can be incrememnted by the proper amount and the ``%=`` operation yields any remaining number of guests if there is overflow from the room.

Afterwards, the tax on the room is computed as the ``room cost * 0.065`` for 6.5% state tax. This number is then added back to the room cost to get the room total. The meal costs are straightforward: ``number of meals * meal cost``. The meal tax is the sum of the meal costs multiplied by the gratuity of 18%. The total is, then, the sum of all of these numbers.

At this point, the program simply prints the results in a tabular format for a more attractive looking bill (messy bills don't earn large tips).
