/** 
 * @param {string} s consists of parentheses only '()[]{}'.
 * @return {boolean}
 */
function isValid(s: string): boolean {
  const length = s.length;

  if (length % 2 !== 0) {
    return false;
  }

  const parenthesesMap = new Map<string, string>();
  parenthesesMap.set("(", ")");
  parenthesesMap.set("[", "]");
  parenthesesMap.set("{", "}");

  const resultStack: string[] = [];

  for (let i = 0; i < length; i += 1) {
    const curStr = s[i];
    if (parenthesesMap.has(curStr)) {
      resultStack.push(curStr);
    } else {
      const nearestOpen = resultStack.pop();
      if (nearestOpen === undefined) {
        return false;
      }
      if (parenthesesMap.get(nearestOpen) !== curStr) {
        return false;
      }
    }
  }

  return resultStack.length === 0;
};

// (), {([]}), ([)], {{()}}[]()
const input = "()"
const res = isValid(input);
