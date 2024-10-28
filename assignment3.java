import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import org.apache.poi.ss.usermodel.*;

public class ExcelReader {
    public static void main(String[] args) {
        try {
            // Replace "your_excel_file.xlsx" with the actual file path
            FileInputStream file = new FileInputStream(new File("example.xlsx"));

            // Create a Workbook object
            Workbook workbook = WorkbookFactory.create(file);

            // Get the first sheet
            Sheet sheet = workbook.getSheetAt(0);

            // Iterate over rows and columns
            for (Row row : sheet) {
                for (Cell cell : row) {
                    // Get the cell type and value
                    CellType cellType = cell.getCellType();
                    String cellValue = "";

                    switch (cellType) {
                        case STRING:
                            cellValue = cell.getStringCellValue();
                            break;
                        case NUMERIC:
                            cellValue = String.valueOf(cell.getNumericCellValue());
                            break;
                        case BOOLEAN:
                            cellValue = String.valueOf(cell.getBooleanCellValue());
                            break;
                        case FORMULA:
                            cellValue = cell.getCellFormula();
                            break;
                        default:
                            cellValue = "Unknown";
                    }

                    // Print the cell value
                    System.out.print(cellValue + "\t");
                }
                System.out.println();
            }

            // Close the workbook
            workbook.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
