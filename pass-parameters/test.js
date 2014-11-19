var parameter = require('./');

console.log("a: ", parameter.getParameter("a"));
console.log("b: ", parameter.getParameter("b"));
console.log("test: ", parameter.getParameter("test"));

console.log("0: ", parameter.getParameter(0));
console.log("1: ", parameter.getParameter(1));
console.log("201: ", parameter.getParameter(2014));

console.log("T: ", parameter.getParameter(true));
console.log("F: ", parameter.getParameter(false));


console.log("[]: ", parameter.getParameter([]));
console.log("[ 'tim' ]: ", parameter.getParameter([ 'tim' ]));
console.log("[ 'tim', 'roth', 'randy' ]: ", parameter.getParameter([ 'tim', 'roth', 'randy' ]));

console.log("{}: ", parameter.getParameter({}));
console.log("{a: 'b', c: 'd'}: ", parameter.getParameter({a: 'b', c: 'd'}));

try {
    console.log("e: 0 param", parameter.getParameter());
} catch (e) {
    console.log(e);
}

try {
    console.log("e: > 1 param", parameter.getParameter(1, 2));
} catch (e) {
    console.log(e);
}


