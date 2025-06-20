import type { ReactNode } from "react";
import useDocusaurusContext from "@docusaurus/useDocusaurusContext";
import Layout from "@theme/Layout";

import { Box, Button, Container, Typography } from "@mui/material";
import Link from "@docusaurus/Link";

export default function Home(): ReactNode {
  const { siteConfig } = useDocusaurusContext();
  return (
    <Layout title={siteConfig.title}>
      <Container sx={{ display: "flex", flexDirection: "column", alignItems: "center", paddingTop: 2 }}>
        <Typography variant="h4">Welcome to</Typography>
        <Box display="flex" alignItems="center" gap={2}>
          <Box>
            <Typography variant="h2" align="right">
              The
            </Typography>
            <Typography variant="h2">Algorithm</Typography>
            <Typography variant="h2" align="right">
              Box
            </Typography>
          </Box>
          <img src="img/Logo.png" height="400" />
        </Box>
        <Box display="flex" gap={4}>
          <Link>
            <Button variant="outlined">Let's dive in!</Button>
          </Link>
          <Link href="/about">
            <Button variant="outlined">What is the Algorithm Box?</Button>
          </Link>
          <Link href="/whoami">
            <Button variant="outlined">Who am I?</Button>
          </Link>
        </Box>
      </Container>
    </Layout>
  );
}
