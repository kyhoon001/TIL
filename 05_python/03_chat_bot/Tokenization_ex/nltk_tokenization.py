import nltk
from nltk.tokenize import word_tokenize
from nltk.tokenize import WordPunctTokenizer

nltk.download('punkt')

print(word_tokenize("Don't be a jerk is a fundamental rule of all social spaces. Every other policy for getting along with others is a special case of this rule."))
print(WordPunctTokenizer().tokenize("Don't be a jerk is a fundamental rule of all social spaces. Every other policy for getting along with others is a special case of this rule."))
