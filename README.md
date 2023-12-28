# CLCD_3Button-Calculator

 a 3-button calculator on the Atmega32 microcontroller! 💻
⚡Operations:

    📌3 intuitive buttons: '⬆️ Up,' '⬇️ Down,' and '➡️ Enter.'

      ⬆️ Up' increments the current number.

      ⬇️ Down' decrements the number.

      ➡️ Enter' shifts the cursor; landing on '=', it displays the result.

    📌Basic operations (+, -, *, /) between two integers 🧮



⚡Features:

    -Intelligent handling of illogical operations, preventing division by 0 🚫

    -Floating-point results displayed for division operations 🌊

⚡Hardware Components:

    💡 CLCD (Character LCD)

    🔘 Push Buttons

⚡Software Architecture:

     -Utilized a layered architecture approach 🏗️

     -MCAL Layer: Implemented DIO_driver for low-level operations

     -HAL Layer: Employed CLCD_driver with pre-built configurations 🛠️

