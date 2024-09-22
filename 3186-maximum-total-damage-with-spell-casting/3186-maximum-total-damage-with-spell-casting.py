class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:

        # Count the frequency of each unique damage value
        count = Counter(power)

        # Create a sorted list of unique damage values
        unique_powers = sorted(count.keys())

        # Edge case: if there is only one unique power
        if len(unique_powers) == 1:
            return unique_powers[0] * count[unique_powers[0]]

        # Initialize two variables to store max damage up to the previous and second previous spells
        prev1 = 0  # Maximum damage if we don't cast the current spell
        prev2 = 0  # Maximum damage if we cast the current spell
        prev3 = 0  # Maximum damage if we cast the current spell
        
        # Iterate through the sorted unique powers
        for i in range(len(unique_powers)):
            # Calculate the total damage for this particular power group
            current_power_value = unique_powers[i] * count[unique_powers[i]]

            # If the current power is not adjacent to the previous power (i.e., difference > 1)
            if i == 0 or unique_powers[i] > unique_powers[i-1] + 2:
                # Safe to cast the current spell, max is prev1 + current damage
                current = prev1 + current_power_value
            else:
                # If current power is adjacent, we have two options:
                # 1. Skip the current power and take prev1
                # 2. Cast the current power, skip the adjacent one, and take prev2 + current damage
                current = max(prev1, prev2 + (current_power_value if unique_powers[i]-unique_powers[i-2]>2 else 0), prev3 + current_power_value)

            # Update prev2 and prev1 for the next iteration
            prev3, prev2, prev1 = prev2, prev1, current

        # The result is the max damage obtained
        return prev1