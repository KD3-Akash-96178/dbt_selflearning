
class ECommerceException extends Exception {
    public ECommerceException(String message) {
        super(message);
    }
}

class PaymentException extends ECommerceException {
    public PaymentException(String message) {
        super(message);
    }
}

class InsufficientFundsException extends PaymentException {
    public InsufficientFundsException() {
        super("Payment failed: Insufficient funds.");
    }
}

class InvalidPaymentMethodException extends PaymentException {
    public InvalidPaymentMethodException() {
        super("Payment failed: Invalid payment method.");
    }
}

class InventoryException extends ECommerceException {
    public InventoryException(String message) {
        super(message);
    }
}

class OutOfStockException extends InventoryException {
    public OutOfStockException() {
        super("Inventory error: Product is out of stock.");
    }
}

class InvalidProductException extends InventoryException {
    public InvalidProductException() {
        super("Inventory error: Invalid product.");
    }
}

class ShippingException extends ECommerceException {
    public ShippingException(String message) {
        super(message);
    }
}

class InvalidAddressException extends ShippingException {
    public InvalidAddressException() {
        super("Shipping error: Invalid address.");
    }
}

class DeliveryUnavailableException extends ShippingException {
    public DeliveryUnavailableException() {
        super("Shipping error: Delivery not available in this area.");
    }
}

class OrderService {

    void processPayment(double amount, String method) throws PaymentException {
        if (amount <= 0) {
            throw new InsufficientFundsException();
        }
        if (!method.equals("CARD") && !method.equals("UPI")) {
            throw new InvalidPaymentMethodException();
        }
        System.out.println("Payment successful!");
    }

    void checkInventory(int quantity) throws InventoryException {
        if (quantity <= 0) {
            throw new OutOfStockException();
        }
        System.out.println("Inventory available!");
    }

    void shipOrder(String address) throws ShippingException {
        if (address == null || address.isEmpty()) {
            throw new InvalidAddressException();
        }
        if (address.equalsIgnoreCase("RemoteArea")) {
            throw new DeliveryUnavailableException();
        }
        System.out.println("Order shipped successfully!");
    }
}

public class SLQ6 {
    public static void main(String[] args) {

        OrderService service = new OrderService();

        try {
            service.processPayment(0, "CARD"); // triggers exception
            service.checkInventory(5);
            service.shipOrder("Delhi");
        } catch (PaymentException e) {
            System.out.println(e.getMessage());
        } catch (InventoryException e) {
            System.out.println(e.getMessage());
        } catch (ShippingException e) {
            System.out.println(e.getMessage());
        } catch (ECommerceException e) {
            System.out.println("General error: " + e.getMessage());
        }

        System.out.println("\n--- Second Scenario ---");

        try {
            service.processPayment(1000, "UPI");
            service.checkInventory(0);
            service.shipOrder("Delhi");
        } catch (ECommerceException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\n--- Third Scenario ---");

        try {
            service.processPayment(500, "CARD");
            service.checkInventory(2);
            service.shipOrder("RemoteArea"); 
        } catch (ECommerceException e) {
            System.out.println(e.getMessage());
        }
    }
}

