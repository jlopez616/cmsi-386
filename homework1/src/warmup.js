exports.change = (amount) => {
  if (amount < 0) {
    throw new RangeError('Amount cannot be negative');
  }

  let remaining = amount;
  const quarters = Math.floor(remaining / 25);
  remaining %= 25;
  const dimes = Math.floor(remaining / 10);
  remaining %= 10;
  const nickels = Math.floor(remaining / 5);
  remaining %= 5;
  const pennies = remaining;
  return [quarters, dimes, nickels, pennies];
};

exports.powers = (base, limit, callback) => {
  let value = 1;
  while (value <= limit) {
    callback(value);
    value *= base;
  }
};

exports.powersGenerator = function* (base, limit) {
  let value = 1;
  while (value <= limit) {
    yield value;
    value *= base;
  }
};

exports.interleave = function (...argsList) {
  const args = Array.from(argsList);
  const first = args.shift();
  first.forEach((iterator, index) => {
    args.splice(index * 2, 0, first[index]);
  });
  return args;
};


exports.cylinder = (spec) => {
  const undefinedTest = (data) => {
    if (data !== undefined) {
      return data;
    }
    return 1;
  };

  let { height, radius } = {
    height: undefinedTest(spec.height),
    radius: undefinedTest(spec.radius),
  };

  const widen = (value) => { radius *= value; };
  const stretch = (value) => { height *= value; };
  const volume = () => Math.PI * (radius ** 2) * height;
  const surfaceArea = () => (2 * Math.PI * radius * height) + (2 * Math.PI * (radius ** 2));
  const toString = () => `Cylinder with radius ${radius} and height ${height}`;
  return Object.freeze({
    get radius() { return radius; },
    get height() { return height; },
    widen,
    stretch,
    volume,
    surfaceArea,
    toString,
  });
};


exports.randomName = function (data) {
  const rp = require('request-promise');
  const options = { uri: 'http://uinames.com/api', qs: { region: data.region, gender: data.gender }, json: true };
  return rp(options).then(json => `${json.surname}, ${json.name}`);
};
