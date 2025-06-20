import { ThemeProvider } from "@mui/material";
import { ReactNode } from "react";
import { TABTheme } from "../components/theme";

export default function Root({ children }: { children: ReactNode[] }) {
  return <ThemeProvider theme={TABTheme}>
    {children}
    </ThemeProvider>;
}
