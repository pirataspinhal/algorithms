# What to contribute?

Write any algorithm, data structure demo or general application in the programming language of your choice, and open a
pull request. Your request will be assigned to one of the maintainers and reviewed as soon as possible.

## Writing a Good Pull Request Description

A well-written PR description helps maintainers understand and review your contribution quickly. Please include:

### ✅ Good Example:
```
## Category
- [x] Sorting Algorithm

## Algorithm/Data Structure Description
This is a Python implementation of Merge Sort algorithm. Merge Sort is a divide-and-conquer algorithm that divides the array into halves, recursively sorts them, and then merges the sorted halves. It guarantees O(n log n) time complexity in all cases.

## Implementation Details
**Programming Language:** Python
**Time Complexity:** O(n log n)
**Space Complexity:** O(n)
**Key Features:** Stable sort, works well with large datasets

## Testing
- [x] Yes, with sample inputs
- [x] Yes, with edge cases
**Test cases included:** Empty array, single element, already sorted array, reverse sorted array
```

### ❌ Poor Examples:
- "Added algorithm" (too vague)
- "Please include a small description of your algorithm/data structure and add reference to the Hacktoberfest issue" (template not filled)
- "Hey! I added XYZ Algorithm." (no technical details)

### Required Information:
1. **Clear algorithm/data structure name and purpose**
2. **Programming language used**
3. **Time and space complexity (if applicable)**
4. **Brief explanation of how it works**
5. **Testing status**

# Are there any rules?

### 1. Make sure to put your code in an appropriate directory

```
├── problem category (or sub-category)
│   ├── programming language
│   │   └── your code!
```

If you don't find a proper location, feel free to create it!

## Code Quality Standards

### Documentation
- Add meaningful comments explaining complex logic
- Include function/method documentation where appropriate
- Consider adding a README.md in your algorithm's directory for complex implementations

### Code Style
- Use descriptive variable and function names
- Follow the standard conventions for your chosen programming language
- Keep functions focused and modular when possible

### Examples to Include
- At least one working example demonstrating your algorithm
- Sample input/output in comments or separate test file
- Edge case handling where relevant

### 2. Make sure that the code you're adding is of your own creation

If you think this goes without saying, then rest assured that this message is not for you; you most likely already abide
by this rule.

[Open source contribution guidelines](https://hacktoberfest.digitalocean.com/details#quality-standards) emphasize quality contributions, and we want to
be in tune with these values. For that however, we maintainers have to be strict when dealing with spam, which is
plenty, unfortunately. So here's how it goes:

- **Spam PRs or PRs containing blatant copies of snippets from the web will be immediately tagged `invalid` and
closed.** We use up our free time to read, review and engage in every pull request made to this repository, and any time
we waste with spam is lost by not properly engaging with developers who actually want to contribute to the event in a
constructive manner.

- **If you think your PR was wrongfully taken down, post a comment on your PR clarifying the issue, or just send a mail
to any of the maintainers (addresses on their respective profiles).** Given the situation described above, it's totally
possible that we end up closing your request by mistake, and we apologize for it. We'll try our best not to though, and
if it does happen, rest assured that we'll respond to any inquiries as fast as possible.

Again, We're very sorry if any of this was not for your ears. We hope you understand our need to state all this.

If you're reading this, we really do hope you make a contribution here. Happy hacking! :smile:

# A note on stale requests

If your pull request has been inactive for too long after a review with requested changes, as in without any follow-ups,
we might end up tagging your request as `stale` and closing it. The conversation will be left open though, and if by
any chance you'd like to follow up on the old PR, just tag any of the maintainers (preferably one of the assignees)
in a comment and we'll re-open and re-review the contribution.
