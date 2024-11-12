# Prefix Expression Calculator

This program evaluates prefix expressions using a stack-based approach. It supports basic arithmetic operations: addition, subtraction, multiplication, and division.

## Features

- Supports prefix expressions with operators (`+`, `-`, `*`, `/`) and operands (numbers).
- Handles expressions with multiple-digit numbers.
- Uses a custom stack data structure to evaluate the expression.

## Usage

1. **Compile the program**: Use a C compiler to compile the code.
   ```sh
   gcc prefix_calculator.c -o prefix_calculator
   ```
2. **Run the program**: Execute the compiled program.
   ```sh
   ./prefix_calculator
   ```

3. **Input Requirements**:
   - Enter the total size of the expression (including spaces and operators).
   - Enter the prefix expression, with each number and operator separated by a space.
   - Example expressions:
     - `+ - 2 7 * 8 / 4 12` (Size: 19)
     - `+ - 9 2 6` (Size: 9)

## Example

Here's an example usage with an expression `+ - 2 7 * 8 / 4 12`.

```
Enter your expression size: 19
Enter the prefix expression:
+ - 2 7 * 8 / 4 12
Result: -2.3333
```

## Code Structure

- **Stack Structure**: The stack is implemented using a linked list, with each node storing a number.
- **Functions**:
  - `push(double x, stackNode** top)`: Pushes a number onto the stack.
  - `pop(stackNode** top)`: Pops the top number from the stack.
  - `doOperation(char operator, double operand1, double operand2)`: Performs the specified arithmetic operation.
  - `substringToDouble(char* start, char* end)`: Converts a substring to a double, used to parse numbers.
  - `instructions()`: Displays user instructions for input format.

## How the Calculator Works

1. **Read the Expression**: The expression is read from right to left (since it's in prefix form).
2. **Evaluate Using a Stack**:
   - For each operator, pop two numbers from the stack, perform the operation, and push the result back onto the stack.
   - For each operand, push it directly onto the stack.
3. **Result**: The final result will be on top of the stack after processing the entire expression.

## Sample Code

The sample code includes all necessary functions to parse, evaluate, and display results for a prefix expression.

## Example Expressions

- `+ - 2 7 * 8 / 4 12` (Size: 19) - Expected result: `-2.3333`
- `+ - 9 2 6` (Size: 9) - Expected result: `13.0000`
  
Make sure the size matches the exact number of characters, including spaces.

## Notes

- The calculator only supports basic arithmetic operations (`+`, `-`, `*`, `/`).
- Each operand and operator should be separated by a space.
- Division operations follow floating-point division rules.
