import csv

'''
So, the way this naive_bays implementation works is as follows:

posterior is a function that takes the prior probability of a variable Class being true and the likelihoood of other dependent variables being true and returns the probability of P(Class = True | Observations).
That is, this function calculates the probability of the parent cause being true based on the observed values of its children.
eg: If Pneumonia occurs in 5% of people and people who have pneumonia have a 80% chance to display coughing and a 60% chance of sore throat and we know that people without pneumonia have a 10% chance to display coughing and a 21% chance of a sore throat, we can calculate the probability of someone having pneumonia if they display both symptomps as:

prior = 0.05
likelihood = ((0.8,0.21),(0.6,0.21))
observation = (True, True)
prob = posterior(prior, likelihood, observation)

We then calculate the "prior" probability in a file and discover the chance of input data being valid or invalid using this posterior function. There is sample data included in this folder called "spam-labelled.csv" which contains a .csv file of data with 12 characteristics that were either true or false and also whether that email was spam or not.
'''

def posterior(prior, likelihood, observation):
    n = len(observation)
    trueProb = prior
    falseProb = 1 - prior
    for count in range(n):
        flag = observation[count]
        true = likelihood[count][True]
        false = likelihood[count][False]
        if not flag:  # Handle this case
            true = 1 - true
            false = 1 - false
        trueProb *= true
        falseProb *= false
    total = trueProb + falseProb
    return trueProb / total

def learn_prior(file_name, pseudo_count=0):
    spam = pseudo_count
    not_spam = pseudo_count
    with open(file_name) as in_file:
        training_examples = [tuple(row) for row in csv.reader(in_file)]
    data = training_examples[1:]
    for row in data:
        x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,spam_flag = row
        spam_flag = int(spam_flag)
        if spam_flag:
            spam += 1
        else:
            not_spam += 1

    total = spam + not_spam
    return spam/total


# Remember for indexing a tuple, False = 0, True = 1.
def learn_likelihood(file_name, pseudo_count=0):
    header_count = 12
    true_approve = [pseudo_count] * header_count
    false_approve = [pseudo_count] * header_count
    true_reject = [pseudo_count] * header_count
    false_reject = [pseudo_count] * header_count
    with open(file_name) as in_file:
        training_examples = [tuple(row) for row in csv.reader(in_file)]
    data = training_examples[1:]
    num_data = len(data)
    for i in range(num_data):
        actual_data = data[i][:-1]
        spam_flag = data[i][-1]
        spam_flag = int(spam_flag)
        for j in range(header_count):
            if spam_flag:
                if actual_data[j] == "1":
                    true_approve[j] += 1
                else:
                    false_approve[j] += 1
            else:
                if actual_data[j] == "1":
                    true_reject[j] += 1
                else:
                    false_reject[j] += 1

    toReturn = []
    for i in range(header_count):
        total = true_reject[i] + false_reject[i]
        first = true_reject[i] / total

        total = true_approve[i] + false_approve[i]
        second = true_approve[i] / total

        this_tuple = (first, second)
        toReturn.append(this_tuple)

    # print(true_approve)
    # print(false_approve)
    # print(true_reject)
    # print(false_reject)
    return toReturn

def nb_classify(prior, likelihood, input_vector):
    chance = posterior(prior, likelihood, input_vector)
    if chance > 0.5:
        return ("Spam", chance)
    else:
        return ("Not Spam", 1- chance)

prior = learn_prior("spam-labelled.csv")
likelihood = learn_likelihood("spam-labelled.csv")

input_vectors = [
    (1,1,0,0,1,1,0,0,0,0,0,0),
    (0,0,1,1,0,0,1,1,1,0,0,1),
    (1,1,1,1,1,0,1,0,0,0,1,1),
    (1,1,1,1,1,0,1,0,0,1,0,1),
    (0,1,0,0,0,0,1,0,1,0,0,0),
    ]

predictions = [nb_classify(prior, likelihood, vector) 
               for vector in input_vectors]

for label, certainty in predictions:
    print("Prediction: {}, Certainty: {:.5f}"
          .format(label, certainty))

