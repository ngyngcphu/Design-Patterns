interface IProduct {
    family: string;
    char: (place: number) => string;
}

class ConcreteProductLeter implements IProduct {
    family: string = 'AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz';
    public char = (place: number): string => {
        const c = this.family.split('');
        place = (place - 1) % c.length;
        return c[place];
    }
}

class ConcreteProductNumber implements IProduct {
    family: string = ')0!1@2#3$4%5^6&7*8(9';
    public char = (place: number): string => {
        const c = this.family.split('');
        place = (place - 1) % c.length;
        return c[place];
    }
}

class ConcreteProductSymbol implements IProduct {
    family: string = '~`_-+={[}]|\:;"\'<,>.?/';
    public char = (place: number): string => {
        const c = this.family.split('');
        place = (place - 1) % c.length;
        return c[place];
    }
}

abstract class ACreator {
    public abstract factoryMethod: () => IProduct;
    public char = (place: number): string => {
        const product: IProduct = this.factoryMethod();
        return product.char(place);
    }
}

class ConcreteCreatorLeter extends ACreator {
    public factoryMethod = (): IProduct => {
        return new ConcreteProductLeter();
    }
}

class ConcreteCreatorNumber extends ACreator {
    public factoryMethod = (): IProduct => {
        return new ConcreteProductNumber();
    }
}

class ConcreteCreatorSymbol extends ACreator {
    public factoryMethod = (): IProduct => {
        return new ConcreteProductSymbol();
    }
}

const test = (creator: ACreator): void => {
    console.log('1 =', creator.char(1));
    console.log('2 =', creator.char(2));
    console.log('3 =', creator.char(3));
}

console.log('Letters:');
test(new ConcreteCreatorLeter());
console.log('Numbers:');
test(new ConcreteCreatorNumber());
console.log('Symbols:');
test(new ConcreteCreatorSymbol());
