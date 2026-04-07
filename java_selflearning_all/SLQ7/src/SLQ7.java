
import java.util.*;

class Product {
    int id;
    String name;
    double price;

    Product(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }
}

class CartItem {
    Product product;
    int quantity;

    CartItem(Product product, int quantity) {
        this.product = product;
        this.quantity = quantity;
    }

    double getTotalPrice() {
        return product.price * quantity;
    }
}

class ShoppingCart {
    private HashMap<Integer, CartItem> cart = new HashMap<>();

    void addProduct(Product p, int qty) {
        if (cart.containsKey(p.id)) {
            cart.get(p.id).quantity += qty;
        } else {
            cart.put(p.id, new CartItem(p, qty));
        }
        System.out.println(p.name + " added to cart.");
    }

    void removeProduct(int productId) {
        if (cart.remove(productId) != null) {
            System.out.println("Product removed.");
        } else {
            System.out.println("Product not found.");
        }
    }

    void displayCart() {
        double total = 0;
        System.out.println("\n--- CART ITEMS ---");

        for (CartItem item : cart.values()) {
            System.out.println(item.product.name + 
                " | Price: " + item.product.price + 
                " | Qty: " + item.quantity + 
                " | Total: " + item.getTotalPrice());

            total += item.getTotalPrice();
        }

        System.out.println("Cart Total: " + total);
    }

    double checkout() {
        double total = 0;
        for (CartItem item : cart.values()) {
            total += item.getTotalPrice();
        }
        cart.clear();
        return total;
    }
}

class Order {
    List<CartItem> items;
    double totalAmount;

    Order(List<CartItem> items, double totalAmount) {
        this.items = items;
        this.totalAmount = totalAmount;
    }

    void displayOrder() {
        System.out.println("\nOrder Details:");
        for (CartItem item : items) {
            System.out.println(item.product.name + " x " + item.quantity);
        }
        System.out.println("Total Paid: " + totalAmount);
    }
}

public class SLQ7 {
    public static void main(String[] args) {

        // Products
        Product p1 = new Product(1, "Laptop", 50000);
        Product p2 = new Product(2, "Phone", 20000);
        Product p3 = new Product(3, "Headphones", 2000);

        ShoppingCart cart = new ShoppingCart();
        ArrayList<Order> orderHistory = new ArrayList<>();

        // Add items
        cart.addProduct(p1, 1);
        cart.addProduct(p2, 2);
        cart.addProduct(p3, 3);

        cart.displayCart();

        // Checkout
        double total = cart.checkout();

        // Save order (copy items manually)
        List<CartItem> orderItems = new ArrayList<>();
        orderItems.add(new CartItem(p1, 1));
        orderItems.add(new CartItem(p2, 2));
        orderItems.add(new CartItem(p3, 3));

        Order order = new Order(orderItems, total);
        orderHistory.add(order);

        // Display order history
        System.out.println("\n--- ORDER HISTORY ---");
        for (Order o : orderHistory) {
            o.displayOrder();
        }
    }
}
