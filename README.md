# 209poll
Epitech Project, MATHS 209

Subject:

Several months before an important election, many polls seem to pop up from nowhere. Their interpreta-tions are often surrounded by uncertainty: to what extent are these polls reliable? Why are there so manydifferences between poll institutes? And from day to day? Is a 3% variation significant? etc. . .

To estimate the accuracy of the results, aconfidence intervalis given. It is defined by the fact that there is ax% probability that this interval encompasses the true value.

You already know that questioning people follows a Bernoulli process, and therefore that a binomial dis-tribution (converging toward a normal distribution) is a good model for the results. You can then easilycompute the confidence intervals, knowing that:
  •the 95% confidence interval amplitude is2×1.96√v
  •the 99% confidence interval amplitude is2×2.58√v
  
where v stands for the variance of the sample proportion (corrected for finite populations).
  
The goal of this project is to compute the 95% and 99% confidence intervals.

Usage:

./209poll pSize sSize p

pSize   size of the population
sSize   size of the sample (supposed to be representative)
p       percentage of voting intentions for a specific candidate

Example:

![alt text](https://github.com/alexandre10044/209poll/blob/master/example.png?raw=true)
