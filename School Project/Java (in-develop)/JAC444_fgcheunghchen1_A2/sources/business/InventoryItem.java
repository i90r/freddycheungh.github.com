package business;

import java.io.*;

/**
 * Interface that will establish the basic prototypes for methods 
 * used in a Inventory App. 
 * 
 * <p></p>
 * 
 *  @version 1.0
 *  @author Freddy Cheungh
 */
public interface InventoryItem
{
	//-------------------------------------------String  decreaseStock(int decAmount)
	/** Decreases the quantityInStock by the amount passed as parameter 1.  Returns the message “Decreased stock of [inventoryId] by [decAmount].”.
	 */
	public String  decreaseStock(int decAmount);

	//_____________________________int formatReportData_1(StringBuffer sb)
	/** Appends  the data from one object, formatted for Report 1, to the StringBuffer passed as parameter 1. Returns a possible error indicator (zero means “no errors”.
	 */
	public int formatReportData_1(StringBuffer sb);


	//--------------------------------------------String getPrimaryKey()
	/** Returns the value of inventoryId (to be used as the key for a Hashtable or database primary key or similar purpose).
	 */
	public String getPrimaryKey(); 
	//--------------------------------------------String  increaseStock(int incAmount)
	/** Increases the quantityInStock by the amount passed as parameter 1.   Returns the message “Increased stock of [inventoryId] by [incAmount].”
	 */ 
	public String  increaseStock(int incAmount);
	//--------------------------------------------String  placeSalesOrder(int qtyOrdered)

	/** Adds the qtyOrdered to totalSalesOrders and returns the message “Sales Order of [qtyOrdered] for [inventoryId].”
	 */
	public String  placeSalesOrder(int qtyOrdered);
	//--------------------------------------------String receiveReplenishment(int qtyReceived)
	/** Reduces the totalOrdered  by the qtyReceived  then calls increaseStock(qtyReceived). 
	 */
	public String receiveReplenishment(int qtyReceived);
	//--------------------------------------------String shipSalesOrder(int qtyShipped)
	/** Reduces totalSalesOrders by the qtyShipped then calls decreaseStock(qtyShipped). 
	 */
	public String shipSalesOrder(int qtyShipped);

}	//end of interface