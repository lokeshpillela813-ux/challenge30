 1 . Start.
 2. Read purchase amount, customer type, and delivery distance.
 3. If customer type is 1:
   - If purchase amount >= 2000, discount percentage = 15%.
   - Otherwise, discount percentage = 10%.
4. Else if customer type is 2:
   - If purchase amount >= 3000, discount percentage = 8%.
   - Otherwise, discount percentage = 0%.
5. Calculate discount amount = purchase amount × discount percentage / 100.
6. If distance <= 5, delivery charge = 40.
7. Else if distance <= 15, delivery charge = 70.
8. Otherwise, delivery charge = 100.
9. Calculate final amount = purchase amount − discount amount + delivery charge.
10. Display purchase amount, discount amount, delivery charge, and final amount.
11. Stop.
